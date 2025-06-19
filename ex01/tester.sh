#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${CYAN}Testing RPN calculator...${NC}"
echo -e "${CYAN}-------------------------${NC}"

if [ ! -f RPN ]; then
	echo -e "${RED}RPN executable not found. Please compile the code first.${NC}"
	exit 1
fi

# Test cases
echo -e "${CYAN}Running test cases...${NC}"
echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"${NC}"
echo -e "${YELLOW}Expected: 42${NC}"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"7 7 * 7 -\"${NC}"
echo -e "${YELLOW}Expected: 42${NC}"
./RPN "7 7 * 7 -"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"1 2 * 2 / 2 * 2 4 - +\"${NC}"
echo -e "${YELLOW}Expected: 0${NC}"
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"(1 + 1)\"${NC}"
echo -e "${YELLOW}Expected: Error: Invalid input.${NC}"
./RPN "(1 + 1)"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"5 1 2 + 4 * + 3 -\"${NC}"
echo -e "${YELLOW}Expected: 14${NC}"
./RPN "5 1 2 + 4 * + 3 -"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"3 4 + 2 * 7 /\"${NC}"
echo -e "${YELLOW}Expected: 2${NC}"
./RPN "3 4 + 2 * 7 /"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"4 2 + 3 5 1 - * +\"${NC}"
echo -e "${YELLOW}Expected: 18${NC}"
./RPN "4 2 + 3 5 1 - * +"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"4 0 /\"${NC}"
echo -e "${YELLOW}Expected: Error: Invalid input.${NC}"
./RPN "4 0 /"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"2 3 ^\"${NC}"
echo -e "${YELLOW}Expected: Error: Invalid input.${NC}"
./RPN "2 3 ^"

echo -e "${CYAN}---------------------${NC}"

echo -e "${GREEN}./RPN \"\"${NC}"
echo -e "${YELLOW}Expected: Error: Invalid input.${NC}"
./RPN ""
