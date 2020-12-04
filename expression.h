#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <list>

//! класс математических выражений
class Expression
{
private:
    //! типы лексем
    enum TokenTypes {
        number,     //!< число
        operate,    //!< оператор
        bracketL,   //!< открывающая скобка
        bracketR,   //!< закрывающая скобка
        function    //!< функция
    };

    //! лексема
    struct Token {
        TokenTypes type;    //!< тип лексемы
        std::string value;  //!< значение лексемы
        Token() : type(number), value("") {}
        Token(TokenTypes _type, const std::string& _value) : type(_type), value(_value) {}
        //! возвращает приоритет лексемы
        signed char getPrior() const;
    };

    //! значения массива для конечного автомата
    enum States {
        st_start = 0,       //!< начальное состояние
        st_int_part,        //!< набор целой части (были цифры)
        st_flt_part_pnt,    //!< набор дробной части (цифр не было, была точка)
        st_uminus,          //!< унарный минус, набор целой части (был знак, цифр не было)
        st_braL,            //!< "("
        st_fact,            //!< "!"
        st_s,               //!< "s"
        st_c,               //!< "c"
        st_t,               //!< "t"
        st_operat,          //!< операция
        st_braR,            //!< ")"
        st_flt_part,        //!< набор дробной части (были цифры)
        st_sin_tan,         //!< "sin", "tan"
        st_q,               //!< "q"
        st_cos,             //!< "cos"
        st_sqrt,            //!< "sqrt"
        error,              //!< ошибка
        OK                  //!< всё в порядке
    };

    static const States SM[16][17]; //!< массив для конечного автомата

    std::list<Token> tokens;        //!< список лексем

    //! проверить число на корректность с помощью конечного автомата
    static bool checkFormula(const std::string& num);

    //! преобразовать список в польскую инверсную запись
    void postfix();

public:
    //! конструктор
    Expression();
    //! деструктор
    ~Expression();

    //! распечатать список
    void print() const;
    //! разбить строку на лексемы и преобразовать в список
    void prepare(const std::string& expr);
    //! вычислить значение выражения
    std::string compute();

private:
    //! конструктор копирования
    Expression(const Expression&);
    //! оператор присваивания
    Expression& operator=(const Expression&);
};

#endif  // EXPRESSION_H