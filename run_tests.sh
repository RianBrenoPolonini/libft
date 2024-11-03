docker build -t libft_test .

# clear

norminette -R CheckForbiddenSourceHeader ./src ./include
echo "\n\n"

docker run libft_test

docker rmi libft_test -f > /dev/null 2>&1
