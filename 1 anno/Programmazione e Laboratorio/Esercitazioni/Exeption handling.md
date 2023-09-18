`std::cin` can be in an  **error state** :
+ extract an int form the stream but the next stream element is not an int
+ when we are at the end of a stream 

If used in a condition `std::cin` is converted to a boolean and can determine if it's in an **error state**


## Throwing exeptions

Handling exeptions with **throw**, **try**, **catch** statements

A function can **throw** a struct/class, if it does the function exits and the caller **catch** the thrown object

Example :

```c++
struct myerror{};

int rect_area(int a, int b){
	if(a < 0 or b < 0) throw myerror();
	return a*b;
}

int main(){
	try{
		std::cout<<rec_area(2, -3)<<std::endl;
	}catch (myerror e) {std::cout<<"error found"<<std::endl;}

return 0;
}
```


**Throwing exeptions**

+ Separetes the error-handling from the regular code
+ better correctness garanteed
+ prevents the caller from aborting in case of errors