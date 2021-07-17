decl
    int result,factorial(int n);
enddecl
int factorial(int n){
    decl
        int f;
    enddecl
    begin
        if( n==1 || n==0 ) then
            f = 1;
        else
            f = n * factorial(n-1);
        endif;
        return f;
    end
}
int main(){
    decl
        int a;
    enddecl
    begin
        read(a);
        result = factorial(a);
        write(result);
        return 1;
    end
}
