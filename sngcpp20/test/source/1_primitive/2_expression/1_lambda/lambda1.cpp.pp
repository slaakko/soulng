int i0 = [](int i){ return i; };
int i1 = [&](int i){ return i; };
int i2 = [=](int i){ return i; };
int i3 = [x] { return x; };
int i4 = [&x] { return x; };
int i5 = [this] { return x; };
int i6 = [*this] { return x; };
int i7 = [x, y]{ return x + y; };
int i8 = [x = 1]{ return x; };
int i9 = [=, x]{ return x; };

