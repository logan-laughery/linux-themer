#ifndef ANIMATEDHOVERBUTTON_H
#define ANIMATEDHOVERBUTTON_H

#include <QPushButton>

class QVariantAnimation;

class AnimatedHoverButton : public QPushButton
{
	Q_OBJECT
public:
	explicit AnimatedHoverButton(const QString &text, QWidget *parent = nullptr);

	void setTransitionDuration(int duration);

	void setPalette(const QPalette &p);

	bool event(QEvent *event) override;

protected:
	void paintEvent(QPaintEvent *) override;

private:
	void animateHover(bool in);

	QVariantAnimation *m_transition;
	int m_duration;
	QColor m_currentColor;
};

#endif // ANIMATEDHOVERBUTTON_H