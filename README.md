# 8*8棋盘回合制采矿对战游戏

支持 Adventurer、JewelHunter、MasterMiner 三种职业，两队轮流采集宝石累计得分。

## 队伍

有两个队伍：**Aces** 和 **King**，每个队伍有三名拥有不同类型的猎人（每个类型各一名）。

## 猎人类型

### 1. Adventurer
- 只能在水平方向上采集相同种类的宝石
- 最多采集 **3** 个

### 2. Jewelhunter
- 可以选择在水平或者垂直方向上采集相同种类的宝石
- 最多采集 **6** 个

### 3. MasterMiner
- 额外有将棋盘上的两行宝石交换位置的能力
- 可以选择在水平方向上或者垂直方向上采集相同种类的宝石
- 最多采集 **max(棋盘的宽，棋盘的长)** 个

## 游戏流程

两个队伍交替出战，每个队伍的操作顺序为：Adventure → Jewelhunter → MasterMiner。等到所有的回合结束后，哪一队采集到的宝石更多，哪一队就获胜。

## 下载

exe可执行文件+演示视频：通过网盘分享的文件：https://pan.baidu.com/s/1ZxkRtfw_n3Szb9oA_WUSjA   提取码: 2823

## 核心工作

1. 4层继承体系（Hunter抽象基类 → Adventurer → Jewelhunter → MasterMiner），运用虚函数多态实现不同种类的猎人采集宝石的差异化行为
2. 完成wipeline函数实现不同方向上的连续宝石消除，swapRows函数实现行交换
