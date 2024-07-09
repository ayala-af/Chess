/// <summary>
/// Represents a coordinate (x, y) on the chess board.
/// </summary>
class Coordinate
{
private:
	/// <summary>
	/// The x-coordinate.
	/// </summary>
	int m_x;

	/// <summary>
	/// The y-coordinate.
	/// </summary>
	int m_y;

public:
	/// <summary>
	/// Constructs a Coordinate object with the given x and y values.
	/// </summary>
	/// <param name="x">The x-coordinate.</param>
	/// <param name="y">The y-coordinate.</param>
	Coordinate(int x, int y) : m_x(x), m_y(y) {}

	/// <summary>
	/// Overloads the equality operator to compare two Coordinate objects for equality.
	/// </summary>
	/// <param name="c1">The first Coordinate object.</param>
	/// <param name="c2">The second Coordinate object.</param>
	/// <returns>True if the coordinates are equal, false otherwise.</returns>
	friend bool operator==(const Coordinate& c1, const Coordinate& c2);

	/// <summary>
	/// Overloads the inequality operator to compare two Coordinate objects for inequality.
	/// </summary>
	/// <param name="c1">The first Coordinate object.</param>
	/// <param name="c2">The second Coordinate object.</param>
	/// <returns>True if the coordinates are not equal, false otherwise.</returns>
	friend bool operator!=(const Coordinate& c1, const Coordinate& c2);

	/// <summary>
	/// Overloads the addition operator to add two Coordinate objects.
	/// </summary>
	/// <param name="c1">The first Coordinate object.</param>
	/// <param name="c2">The second Coordinate object.</param>
	/// <returns>A new Coordinate object representing the sum of the coordinates.</returns>
	friend Coordinate operator+(const Coordinate& c1, const Coordinate& c2);

	/// <summary>
	/// Gets the x-coordinate of the Coordinate object.
	/// </summary>
	/// <returns>The x-coordinate.</returns>
	int getX() const;

	/// <summary>
	/// Gets the y-coordinate of the Coordinate object.
	/// </summary>
	/// <returns>The y-coordinate.</returns>
	int getY() const;

	/// <summary>
	/// Sets the x-coordinate of the Coordinate object.
	/// </summary>
	/// <param name="x">The new x-coordinate.</param>
	void setX(int x);

	/// <summary>
	/// Sets the y-coordinate of the Coordinate object.
	/// </summary>
	/// <param name="y">The new y-coordinate.</param>
	void setY(int y);


};
