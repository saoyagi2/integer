# 初歩の整数論プログラミングソースコード

[初歩の整数論プログラミング](http://www.saoyagi2.net/integer/) のソースコード一式です。詳しくはリンク先のサイトをご覧ください。

## ライセンス

ライセンスは CC0 です。ご自由にご利用ください。

## 開発環境

開発には FreeBSD(amd64) を使用しています。一般的な C89 環境で動作するように心がけています。

一部のプログラムは多倍長整数を扱うために GMP を使用しています。コンパイルする環境に GMP を事前にインストールしてください。

## 実行方法

各ディレクトリに Makefile が用意してあり make コマンドによりビルドが行われます。FreeBSD 環境を想定しているため、それ以外の環境ではコンパイルオプションの調整が必要になる可能性があります。

例: prime ディレクトリの場合
```
$ cd prime
$ make
cc -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp -o prime1 prime1.c
cc -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp -o prime2 prime2.c
cc -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp -o prime3 prime3.c
cc -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp  prime10trillions.c  -o prime10trillions
cc -I/usr/local/include -L/usr/local/lib -O3 -Wall -lgmp -o gmpprime1 gmpprime1.c
```

各プログラムはコマンドラインから探索範囲パラメータを渡して実行することで計算を行います。一部、パラメータが無いプログラムもあります。必要なパラメータは各ソースコードを直接参照ください。

例: prime1 の場合
```
$ ./prime1 2 10
2
3
5
7
```

各プログラムには簡単なテストが用意してあります。`make test` とすることで各プログラムのテストを実行します。

例： prime ディレクトリの場合
```
$ make test
```

プロジェクトのトップディレクトリにも Makefile が設置してあり、こちらで `make` を実行することで、各サブディレクトリに対して繰り返し make を行うことも出来ます。

## 各プログラム説明

### prime

素数を求めるプログラム類です。

* prime1.c - 小さな数で割ってみて素数を求める
* prime2.c - エラトステネスのふるいで素数を求める
* prime3.c - エラトステネスのふるいを繰り返して使って素数を求める
* gmpprime1.c - prim1.c の GMP 対応版
* prime10trillions.c - 10兆以下の素数を求める

### primimisc

素数にまつわる各種プログラムです。

* emirp.c - エマープを求める
* palindromicprime.c - 素数一覧から回文素数を探し出す
* palindromicprime2.c - 差分形式の素数一覧から回文素数を探し出す
* primedigit.c - 素数一覧から各素数の各桁を数える
* primedigit2.c - 差分形式の素数一覧から各素数の各桁を数える
* twinprime.c - 素数一覧から双子素数を探し出す
* twinprime2.c - 差分形式の素数一覧から双子素数を探す
* brotherprime.c - 素数一覧から兄弟素数を探す
* brotherprime2.c - 差分形式の素数一覧から兄弟素数を探す
* primegen.c - 素数生成式の素数生成成績を検証する
* mersenne.c - メルセンヌ数が素数か判定する
* fermat.c - フェルマー数が素数か判定する

一部のプログラムは事前に計算した素数一覧を使用します。素数一覧は以下のように、1行に数字を一つ記載したテキストファイルです。数字は 32bit 整数(int)の範囲です。

```
2
3
5
7
:
```

差分形式の素数一覧は直前の素数との差分を1行に一つの数字を記載したテキストファイルです。最初の 2 のみが素数そのものを記載しています。

差分形式の素数一覧は prime10trillions.c で生成されるため、64bit 整数(long long)の範囲となります。

```
2
1
2
2
:
```

### perfect

完全数を求めるプログラム類です。

* perfect.c - 完全数を求める
* perfectarray.c - 約数の和配列を用いて完全数を求める
* multiplyperfectarray.c - 約数の和配列を用いて倍積完全数を求める

### yuuai

友愛数、婚約数、社交数を求めるプログラムです。

* yuuai.c - 友愛数を求める
* yuuaiarray.c - 約数の和配列を用いて友愛数を求める
* konyaku.c - 婚約数を求める
* konyakuarray.c - 約数の和配列を用いて婚約数を求める
* syakou.c - 社交数を求める
* syakouarray.c - 約数の和配列を用いて社交数を求める

### misc

他に分類できないプログラム類です。

* pythagoras.c - ピタゴラス数を求める
* collatz.c - コラッツ予想を検証する
* collatz2.c - 不要な計算を省いて高速にコラッツ予想を検証する
* goldbach.c - ゴールドバッハ予想を検証する
* ogr.c - 総当たり法で最適ゴロム定規を求める
* ogr2.c - バックトラック法で最適ゴロム定規を求める

### 注意点

int 版のプログラムはコマンドライン引数の指定によってはオーバーフローが発生する危険性があります。
しかし、int 版の主目的はアルゴリズム提示であるので、あえてオーバーフローチェックは行っていません。
オーバーフローが発生するような巨大な数値を扱う場合は GMP 版を用意しているので、そちらを使用するという全体方針です。
