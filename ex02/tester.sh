#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${CYAN}Testing PmergeMe calculator...${NC}"
echo -e "${CYAN}-------------------------${NC}"

if [ ! -f PmergeMe ]; then
	echo -e "${RED}PmergeMe executable not found. Please compile the code first.${NC}"
	exit 1
fi

# Test cases
echo -e "${CYAN}Running test cases...${NC}"
echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./PmergeMe shuf -i 1-100000 -n 3000${NC}"
./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

# loop over values 1 to 3000
for i in $(seq 0 300); do
	echo -e "${GREEN}./PmergeMe shuf -i 1-100000 -n $i${NC}"
	./PmergeMe `shuf -i 1-100000 -n $i | tr "\n" " "`
done