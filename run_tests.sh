docker build -t libft_test .

clear

docker run libft_test

docker rmi libft_test -f > /dev/null 2>&1
