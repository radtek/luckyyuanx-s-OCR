#include <QWidget>

class QImage;

class ImageWidget : public QWidget
{
	Q_OBJECT
public:
	ImageWidget();
	void setImage(QImage* image);

protected:
	void paintEvent(QPaintEvent *event);

private:
	QImage* image;
};