#ifndef SRC_CLASSES_INHERITS_TABLE_TENNIS_H_
#define SRC_CLASSES_INHERITS_TABLE_TENNIS_H_

#include <string>

using std::string;

class TableTennisPlayer
{
private:
  string firstname;
  string lastname;
  bool hasTable;

public:
  TableTennisPlayer (const string &fn = "none", const string &ln = "none",
		     bool ht = false);
  void
  Name () const;
  bool
  HasTable () const
  {
    return hasTable;
  }
  void
  ResetTable (bool v)
  {
    hasTable = v;
  }
};

// public继承: is-a
class RatedPlayer : public TableTennisPlayer
{
private:
  unsigned int rating;
public:
  RatedPlayer (unsigned int r, const string &fn = "none", const string &ln =
		   "none",
	       bool ht = false);
  RatedPlayer (unsigned int r, const TableTennisPlayer &ttp);
  unsigned int
  Rating () const
  {
    return rating;
  }
  void
  ResetRating (unsigned int r)
  {
    rating = r;
  }
};

#endif /* SRC_CLASSES_INHERITS_TABLE_TENNIS_H_ */
