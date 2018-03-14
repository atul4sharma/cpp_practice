//This class is just used to check the flow of the program
class bar
{

    public:
        // Default constructor
        bar();

        // Copy constructor
        bar(bar const & rhs);

        // Copy assignment operator
        bar & operator = (bar const & rhs);

        // Destructor
        ~bar();

#if 1
        // Move constructor
        bar(bar && rhs);

        // Move assignment operator
        bar & operator = (bar && rhs);
#endif
};
