# CPP-Module-09
CPP-Module-09



MacOS: 

		make re && ./PmergeMe $(jot -r 21 1 21 | tr '\n' ' ')
		make re && ./PmergeMe $(for i in {1..21}; do echo $RANDOM $i; done | sort -n | cut -d' ' -f2 | tr '\n' ' ')