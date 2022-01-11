// //
// #include<iostream>
// int main()
// {
//     using namespace std;
//     cout << R"(Jim "King" Tutt uses "\n" instead of endl.)";
    
//     return 0;
// }


#include<iostream>
 struct antarctica_years_end
 {
     int year;
     double month;
     char name[20];
 };

 int main()
 {
     antarctica_years_end s01,s02,s03;
     s01.year = 1998;

     antarctica_years_end *pa = &s02;
     pa->year = 1999;

     antarctica_years_end trio[3];
     trio[0].year = 2003;
     (trio+1)->year = 2004;

     const antarctica_years_end *arp[3] = {&s1,&s2,&s3};
     std::cout << arp[1]->year << std::endl;
     return 0;
 }
 