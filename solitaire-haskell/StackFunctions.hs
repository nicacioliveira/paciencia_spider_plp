module StackFunctions where 

	push :: x -> [x] -> [x]
	push x stack = stack ++ [x]

	top :: [x] -> x
	top [x] = x
	top (x:xs) = top xs

	pop :: [a] -> [a]
	pop [] = error "Stack is Empty!!!"
	pop [x] = []
	pop (x:xs) = x : pop xs

	