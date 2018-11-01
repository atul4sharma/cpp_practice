struct base
{
    void foo(){}
    virtual void bar(){}

    private:
        void private_foo(){}
        void private_bar(){}
    
    protected:
        void protected_foo(){}
        void protected_bar(){}
};


struct derived : public base
{
    void bar() override{}
    void foo() {}
};

int main()
{
    auto obj = base{};     static_cast<void>(obj);
    auto obj2 = derived{}; static_cast<void>(obj2);
    return 0;
}
