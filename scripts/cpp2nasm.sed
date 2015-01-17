1i # This file gets automatically generated
1i # DO NOT TOUCH!
1i

# #define => %define
s|#|%|

# replace single line comments
s|//|;|

# remove multi line comments
/\/\*/{
	:loop
	s|\(.*\)/\*.*\*/|\1|
	t loop

	/\/\*/{
		N
		b loop
	}
}

/%/p
