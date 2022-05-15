#ifndef __EXCEPTIONS_HPP
#define __EXCEPTIONS_HPP

class DateInvalidException : public std::exception
{
   const char *what() const throw()
   {
      return "Entered date is not a possible one.";
   }
};

class NoOpenRoomMatchingCriteriaFoundException : public std::exception
{
   const char *what() const throw()
   {
      return "There is no open room that maches the given criteria.";
   }
};

#endif
