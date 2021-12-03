ifconfig | grep ether | grep -v media | cut -c 8- | tr -d ' '
