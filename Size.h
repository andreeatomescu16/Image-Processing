//
// Created by Andreea on 22.03.2024.
//

#ifndef EXTRA2_SIZE_H
#define EXTRA2_SIZE_H


class Size {
public:
    Size();
    Size(unsigned int width, unsigned int height);

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setWidth(unsigned int new_width);
    void setHeight(unsigned int new_height);

    friend bool operator <(const Size& lhs, const Size& rhs);
    friend bool operator >(const Size& lhs, const Size& rhs);
    friend bool operator ==(const Size& lhs, const Size& rhs);
    friend bool operator <=(const Size& lhs, const Size& rhs);
    friend bool operator >=(const Size& lhs, const Size& rhs);

private:
    unsigned int width;
    unsigned int height;
};


#endif //EXTRA2_SIZE_H
