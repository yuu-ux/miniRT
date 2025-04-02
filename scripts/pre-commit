#!/bin/zsh

# ステージングされた .c ファイルを取得
changed_file=$(git diff --name-only --cached | grep '\.c$')

# フォーマットを適用
for file in ${changed_file};
do
    c_formatter_42 ${file}
done

# フォーマット後に変更を再ステージング
git add ${changed_file}

echo -e "\033[32mpre-commitが完了しました\033[0m"
