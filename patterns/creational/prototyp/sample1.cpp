/**
 * This is only for demonstration purpose
 * Use it at your own Risks
 * @barth.feudong
*/

namespace entity
{
	class EntityInterface
	{
	public:
		virtual~EntityInterface() {}
	};

	class EntityPrototypInterface: public EntityInterface
	{	
	public:
		virtual EntityPrototypInterface& clone()=0;
	public:
		virtual ~EntityPrototypInterface()=default;

	};

	class Point : public EntityPrototypInterface
	{
	private:
		double m_x{};
		double m_y{};
	public:
		Point(double x,double y):m_x(x),m_y(y) {}
		Point(const Point&other){
			m_x = other.m_x;
			m_y = other.m_y;
		}
		~Point() {}
		virtual EntityPrototypInterface& clone(){
			return new Point(*this);                 // TODO: Memory Management...
		}
	};

} // namespace entity


// use the aggregation relationship to interact with the prototype.


int main(){
	using namespace entity;
		auto pt1 = new Point(0.0,10.0);
		auto pt2 = pt1->clone();
		auto pt3 = pt1->clone();
		
}



