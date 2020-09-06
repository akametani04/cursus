# cursus　
* 現在通っている[スクール](https://42tokyo.jp/)で課題として作成したものです。
* 課題の配布はNGのため、成果物のみとなります。

## Usage
* libft : 実際に存在する関数の挙動を理解し、再現したもの。
	* -make allでライブラリ(libft.a)を作成します。
 
* get_next_line　: BUFFER_SIZEずつファイルの中身を読み込み、1行ずつファイルの中身を出力します。
	* ファイル名はコマンドライン引数で入力します。
	* （[sample.txt]というサンプルファイルを入れています。）
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=[１度に読み込むバイト数] get_next_line.c get_next_line_utils.c main.c
./a.out [ファイル名]
```

* ft_printf : printf関数の一部を再現しています。
	* ∟フラグ:マイナスフラグ、０フラグのみ対応
	* ∟最小フィールド値：対応
	* ∟精度：対応∟長さ修飾子：非対応
	* ∟変換指定子：cspdiuxX%対応
	* ∟アスタリスク対応
	* -make allでライブラリ(libftprintf.a)を作成します。
