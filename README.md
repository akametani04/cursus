# cursus
　スクールの課題として作成した関数になります。
　成果物は公開してもいいのですが、課題の配布はNGのためご了承ください。

## Usage
libft　　　　　:　実際に存在する関数の挙動を理解し、再現したもの。
　　　　　　　　　-make allでlibft.aという自作ライブラリを作成します。

get_next_line　:　read関数を使用し、1行ずつファイルの中身を読み取り
　　　　　　　　　出力します。
              　　-gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
                  ※BUFFER_SIZEは32でなくとも動作します。

ft_printf　　　:　printf関数の一部を再現しています。
　　　　　　　　　∟フラグ:マイナスフラグ、０フラグのみ対応
　　　　　　　　　∟最小フィールド値：対応
　　　　　　　　　∟精度：対応
　　　　　　　　　∟長さ修飾子：非対応
　　　　　　　　　∟変換指定子：cspdiuxX%対応
　　　　　　　　　∟アスタリスク対応
　　　　　　　　　-make allでlibftprintf.aという自作ライブラリが作成されます。
