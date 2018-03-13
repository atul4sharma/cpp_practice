//This class is just used to check the flow of the program
class Bar
{

    public:
        // Default constructor
        Bar();

        // Copy constructor
        Bar(Bar const & rhs);

        // Copy assignment operator
        Bar & operator = (Bar const & rhs);

        // Destructor
        ~Bar();

#if 1
        // Move constructor
        Bar(Bar && lhs);

        // Move assignment operator
        Bar & operator = (Bar && rhs);
#endif
};
