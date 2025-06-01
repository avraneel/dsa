#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack) {
    if(stack.empty()) {
        std::cout << "\t(Stack: Empty)";
    }
    else 
    {   
        std::cout << "\t(Stack: ";
        for(auto num:stack) {
            std::cout << num << ' ';
        }
        std::cout << ")";
    }
    

    std::cout << "\t\tCapacity: " << stack.capacity() << " Length: " << stack.size() << "\n";
}

void push(std::vector<int>& stack, int item) {
    stack.push_back(item);
    std::cout << "Push " << item;
    printStack(stack);
}

void pop(std::vector<int>& stack) {
    stack.pop_back();
    std::cout << "Pop ";
    printStack(stack);
}

int main() {
    std::vector<int> stack{};
    printStack(stack);

    push(stack,1);
    push(stack,2);
    push(stack,3);

    pop(stack);

    push(stack, 4);

    pop(stack);
    pop(stack);
    pop(stack);

	return 0;
}