#ifndef SRC_CLASSES_CONVERSION_STONE_WT_H_
#define SRC_CLASSES_CONVERSION_STONE_WT_H_

class StoneWT
{
private:
//  enum
//  {
//    LBS_PER_STN = 14
//  };
  static const int LBS_PER_STN = 14;
  // representation1
  int stone;
  double pds_left;
  // representation2
  double pounds;
public:
  StoneWT (double lbs);
  StoneWT (int stn, double lbs);
  StoneWT ();
  ~StoneWT ();

  void
  show_lbs () const;
  void
  show_stn () const;

  // 转换函数
  explicit
  operator int () const;
  explicit
  operator double () const;
};

#endif /* SRC_CLASSES_CONVERSION_STONE_WT_H_ */
