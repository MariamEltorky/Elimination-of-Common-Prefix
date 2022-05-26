# Elimination-of-Common-Prefix
The implementation of common prefix removable technique that is useful in grammar transformation used in top-down 
parsing by Recursive Descent that because top-down parsing cannot handle common prefix in grammar because The parser cannot determine whether to 
expand a nonterminal A to αβ1 or αβ2 or … or αβn so it is a prerequisite for most of the grammar that is to be input to the top-down parser. And we must solve this 
big problem so, I tried to handle this big problem in my project to help Computer scientists to solve left factoring faster and easier using language C++.

## If we have this rule in grammar:
### <Factor> ::= <term> | <term> + <object> | <term> * <expr>
## We left factor the grammar that : 
###<Factor> ::= <term> < Arguments> 
###<Arguments> ::= + <object> | * <expr> | €
