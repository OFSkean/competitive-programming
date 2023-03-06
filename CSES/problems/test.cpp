#include <bits/stdc++.h>

template <typename F>
void use_func(F* func) {
    const char* name = "use_func";
    (*func)(name);
}

int main() {
    std::array<int, 100> blob;
    auto lambda = [&blob](const char* callee){ 
        printf("This lambda is invoked from %s", callee);
		blob[1] = 47;
    };
	std::cout << blob[1] << std::endl;
    use_func(&lambda);
	std::cout << blob[1] << std::endl;
}
