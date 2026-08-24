```shell
git clone -o bb git@bitbucket.org:ponyatov/ovm.git
cd ~/ovm
```
```shell
git checkout --orphan shadow
ln -fs ~/rc rc
git add -A ; git commit -a -m "."
git push -v -u bb shadow
```
```shell
./rc
```
```shell
cp -r ~/Fy/.vscode ./
```
[[VSCode/settings]]
[[VSCode/extensions]]
```shell
mkdir bin doc lib src tmp
```
```shell
echo '!.gitignore' >> .gitignore
tail -n1 .gitignore >> bin/.gitignore
tail -n1 .gitignore >> doc/.gitignore
tail -n1 .gitignore >> lib/.gitignore
tail -n1 .gitignore >> src/.gitignore
tail -n1 .gitignore >> tmp/.gitignore
```

## files

```shell
touch README.md Makefile .gitignore apt.dev apt.txt .clang-format doxy.gen
```
```
mkdir inc
touch src/ovm.cpp inc/ovm.hpp
touch src/ovm.lex src/ovm.yacc
```
