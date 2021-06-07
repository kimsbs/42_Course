#!/bin/bash
echo -e "\033[32;1m"NORM"\033[m"
read $a
norminette ./*.c ./*.h ./libft/*.c ./libft/*.h
​
echo -e "\033[32;1m"pft"\033[m"
read $a
git clone https://github.com/gavinfielder/pft.git
cd pft
make re
./test
cd ..
​
echo -e "\033[32;1m"42TESTERS-PRINTF"\033[m"
read $a
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
cd 42TESTERS-PRINTF
./runtest.sh
cd ..
​
echo -e "\033[32;1m"PFT_2019"\033[m"
read $a
git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >> .gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
make re
./test
cd ..
​
echo -e "\033[32;1m"PRINTF_TESTER"\033[m"
read $a
rm -rf pft/ 42TESTERS-PRINTF/ pft_2019/
git clone https://github.com/Kwevan/FT_PRINTF_TESTER tests451 && cd tests451 && bash run.sh
cd ..
rm -rf tests451/
​
echo -e "\033[32;1m"ft_printf_test"\033[m"
read $a
git clone https://github.com/cacharle/ft_printf_test.git
cd ft_printf_test/
sed -i "" 's/..\/ft_printf/..\//' Makefile
make run
cd ..
rm -rf ft_printf_test/
​
echo -e "\033[32;1m"PRINTF_LOVER_V2"\033[m"
read $a
git clone https://github.com/charMstr/printf_lover_v2.git
cd printf_lover_v2/
./printf_lover.sh
cd ..
rm -rf printf_lover_v2/
​
echo -e "\033[32;1m"make fclean"\033[m"
read $a
make
make fclean
ls
echo -e "\033[32;1m"make clean"\033[m"
read $a
make
make clean
ls
echo -e "\033[32;1m"make all"\033[m"
read $a
make all
ls
echo -e "\033[32;1m"relink"\033[m"
read $a
make
echo -e "\033[32;1m"DONE"\033[m"
