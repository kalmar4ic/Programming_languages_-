#ifndef Ball_h
#define Ball_h
class Ball
{
private:
	double center_x;
	double center_y;
	double center_z;
	double radius;
	static int count;

public:

	Ball();
	Ball(double c_x, double c_y, double c_z, double r);
	Ball(const Ball& V);
	~Ball() { count--; }

	void Out();
	double Square();

	const Ball& operator= (const Ball& V);
	const Ball& operator*= (const float s);
	bool operator< (const float s);

	friend istream& operator>> (istream& stream, Ball& B);
	friend ostream& operator<< (ostream& stream, const Ball& B);

	static int GetCount();
};
#endif
