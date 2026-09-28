#!/usr/bin/env python3

#
# Created by wsnzg6 on 2026/9/28.
# Copyright(c) 2026 ZGTeam233.
#

import re
from pathlib import Path
from typing import List, Tuple
from pypinyin import lazy_pinyin, Style


class DrugDataGenerator:
    """从原始药材清单生成“简拼 药名”数据文件。"""

    _CHINESE_RE = re.compile(r'[\u4e00-\u9fff]+')

    # 中药多音字修正表：字 -> 应取的首字母拼音
    _OVERRIDES = {
        '术': 'z',   # 莪术、白术、苍术
        '芪': 'q',   # 黄芪、红芪
        '薢': 'b',   # 绵萆薢 bì xiè
        '薷': 'r',   # 香薷 rú
        '苋': 'x',   # 马齿苋 xiàn
        '豨': 'x',   # 豨签草 xī
        '茯': 'f',   # 茯苓
        '芎': 'x',   # 川芎
        '桔': 'j',   # 桔梗
        '蒡': 'b',   # 牛蒡子
    }

    def __init__(self, source: str, target: str) -> None:
        self._source = Path(source)
        self._target = Path(target)
        self._drugs: List[Tuple[str, str]] = []   # (简拼, 药名)

    # ---------- 内部方法 ----------
    def _extract_name(self, raw: str) -> str:
        """从一行文本中提取纯汉字药名。"""
        return ''.join(self._CHINESE_RE.findall(raw))

    def _char_initial(self, ch: str) -> str:
        """取单字的拼音首字母，优先使用修正表。"""
        if ch in self._OVERRIDES:
            return self._OVERRIDES[ch]
        result = lazy_pinyin(ch, style=Style.FIRST_LETTER)
        return result[0] if result else ''

    def _to_jianpin(self, name: str) -> str:
        return ''.join(self._char_initial(c) for c in name)

    # ---------- 对外方法 ----------
    def load(self) -> 'DrugDataGenerator':
        seen = set()
        for raw in self._source.read_text(encoding='utf-8').splitlines():
            name = self._extract_name(raw)
            if not name or name in seen:
                continue
            seen.add(name)
            jp = self._to_jianpin(name)
            if jp:
                self._drugs.append((jp, name))
        return self

    def save(self) -> 'DrugDataGenerator':
        lines = [f"{jp} {name}" for jp, name in self._drugs]
        self._target.write_text('\n'.join(lines), encoding='utf-8')
        return self

    @property
    def count(self) -> int:
        return len(self._drugs)

    def run(self) -> None:
        self.load().save()
        print(f"生成 {self.count} 条记录 -> {self._target}")


if __name__ == '__main__':
    DrugDataGenerator('input.txt', 'drugs_jp.txt').run()