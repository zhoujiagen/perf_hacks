#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

template<typename T>
  void
  f (const T &param)
  {
    using std::cout;
    using std::endl;
    using boost::typeindex::type_id_with_cvr;

//    T = Widget const*
//    param = Widget const* const&
    cout << "T = " << type_id_with_cvr<T> ().pretty_name () << endl;
    cout << "param = " << type_id_with_cvr<decltype(param)> ().pretty_name ()
	<< endl;
  }

class Widget
{
};

std::vector<Widget>
createVec ()
{
  // mock
  return std::vector<Widget> (2);
}

int
main (int argc, char **argv)
{
  using namespace std;
  using boost::typeindex::type_id_with_cvr;

  const auto vw = createVec ();
  if (!vw.empty ())
    {
      f (&vw[0]);
    }

  cout << endl;

//  x = int
//  cx = int const
//  rx = int const&
  auto x = 27;
  const auto cx = x;
  const auto &rx = x;
  cout << "x = " << type_id_with_cvr<decltype(x)> ().pretty_name () << endl;
  cout << "cx = " << type_id_with_cvr<decltype(cx)> ().pretty_name () << endl;
  cout << "rx = " << type_id_with_cvr<decltype(rx)> ().pretty_name () << endl;

  cout << endl;

//  x3 = std::initializer_list<int>
//  x4 = int
  auto x3 =
    { 27 };
  cout << "x3 = " << type_id_with_cvr<decltype(x3)> ().pretty_name () << endl;
  auto x4
    { 27 };
  cout << "x4 = " << type_id_with_cvr<decltype(x4)> ().pretty_name () << endl;

  return 0;
}
