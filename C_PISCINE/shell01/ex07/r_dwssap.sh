cat /etc/passwd | grep -v '#' | sed -n 'n;p' | sed 's/[:].*$//' | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2 p" | sed 's/$/, /' | tr -d "\n" | sed 's/, $/./' | tr -d "\n"
