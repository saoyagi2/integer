# 初歩の整数論プログラミングソースコード

[初歩の整数論プログラミング](http://www.saoyagi2.net/integer/)のソースコード一式です。詳しくはリンク先のサイトをご覧ください。

## ライセンス

ライセンスはCC0です。ご自由にご利用ください。

## 各プログラム説明

### prime

素数を求めるプログラム類です。

* prime1.c - 小さな数で割ってみて素数を求める
* prime2.c - エラトステネスのふるいで素数を求める
* prime3.c - エラトステネスのふるいを繰り返して使って素数を求める
* gmpprime1.c - prim1.cのGMP対応版
* prime10trillions.c - 10兆以下の素数を求める

### primimisc

素数にまつわる各種プログラムです。

* emirp.c - エマープを求める
* palindromicprime.c - 素数一覧から回文素数を探し出す
* primedigit.c - 素数一覧から各素数の各桁を数える
* twinprime.c - 素数一覧から双子素数を探し出す
* twinprime2.c - 差分形式の素数一覧から双子素数を探す
* brotherprime.c - 素数一覧から兄弟素数を探す
* brotherprime2.c - 差分形式の素数一覧から兄弟素数を探す
* primegen.c - 素数生成式の素数生成成績を検証する
* mersenne.c - メルセンヌ数が素数か判定する
* fermat.c - フェルマー数が素数か判定する

### perfect

完全数を求めるプログラム類です。

* perfect.c - 完全数を求める
* perfectarray.c - 約数の和配列を用いて完全数を求める
* multiplyperfect.c - 約数の和配列を用いて倍積完全数を求める

### yuuai

友愛数、婚約数、社交数を求めるプログラムです。

* yuuai.c - 友愛数を求める
* konyaku.c - 婚約数を求める
* syakou.c - 社交数を求める

### misc

他に分類できないプログラム類です。

* pythagoras.c - ピタゴラス数を求める
* collatz.c - 子らっつ予想を検証する
* goldbach.c - ゴールドバッハ予想を検証する
* goldbach2.c - 素数配列を用いて高速にゴールドバッハ予想を検証する
* ogr.c - 総当たり法で最適ゴロム定規を求める
* ogr2.c - バックトラック法で最適ゴロム定規を求める
