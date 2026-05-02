Library UML Analysis

class Library:
* no public or accesible attributes
* associated with Librarian
* composed of Books (1 Library with up to 1000 Books)
* aggregated of members

Class Librarian:
* salary is public
* associated with Library
* inherits from Member class (completely redundant)

Class Member:
* no public or accesible attributes
* aggreagted to Library
* associated with Loan
* Librarian is child class

Class Book:
* title, isbn ans available are all public
* child classes are PrintedBook and EBook
* Libraray is composed of books (eng gebunden mit Library)
* Loan is composed of exactly one book

Class Printed Book and EBook
* No public attributes
* inherit from Book class

Class Loan:
* no public attributes
* 1 Loan is composed of 1 Book
* 0 to n Loans are associated with 1 member

###############################################
What is correct:
* PrintedBook and EBook should inherit from book

Assumption: either there is only ine Library or else Books and LMembers/Libraians cannot be shared between Libraries (they are entirely seperate and own their books and members)
What should be fixed:
* Libraray and Loan cannot both have full ownership of Book!
  -> A Book still exists when the Loan is finished: should be aggregation
  -> Books are fully owned by the Library so that can remain a compostions

* Book attributes should be protected, not public, as its children can still access those

* Members should be composed of Loans, because Loans cannot exist independently of Members

* As the design currently stands, the overlap between Member and Librarian is very small and habe different functions, and especialy since the Librarian is not just a type of Member but actually not primamirly a Member, it shouldn't inherit from Member, but be a standalone class that is owned by (composition) the Library.

* Additionally, since you can't be a Libraray member if the Libraray doesn't exist (and we asssume a 1 -> 1..n relationship between Library and Member), Mebers should be owned by (composition) the Library



