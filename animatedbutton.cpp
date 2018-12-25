#include "animatedbutton.h"
#include <QVariantAnimation>
#include <QStyleOptionButton>
#include <QStylePainter>
#include <QEvent>

AnimatedHoverButton::AnimatedHoverButton(const QString &text, QWidget *parent) :
	QPushButton(text, parent),
	m_transition(nullptr),
	m_duration(1000),
	m_currentColor(palette().brush(QPalette::Button).color())
{

}

void AnimatedHoverButton::setTransitionDuration(int duration)
{
	m_duration = duration;
}

void AnimatedHoverButton::setPalette(const QPalette &p)
{
	QPushButton::setPalette(p);

	m_currentColor = p.brush(QPalette::Button).color();
}

bool AnimatedHoverButton::event(QEvent *event)
{
	switch (event->type()) {
	case QEvent::HoverEnter:
		animateHover(true);
		break;
	case QEvent::HoverLeave:
		animateHover(false);
		break;
	}

	return QPushButton::event(event);
}

void AnimatedHoverButton::paintEvent(QPaintEvent * /*event*/)
{
	QStylePainter painter(this);
	QStyleOptionButton option;
	QPalette p(palette());

	initStyleOption(&option);

	p.setBrush(QPalette::Button, m_currentColor);

	option.palette = p;
	option.state |= QStyle::State_MouseOver;

	painter.drawControl(QStyle::CE_PushButton, option);
}

void AnimatedHoverButton::animateHover(bool in)
{
	const QColor &baseColor(palette().brush(QPalette::Button).color());
	const QColor &highlightColor(palette().brush(QPalette::Highlight).color());
	QColor startValue(in ? baseColor : highlightColor);

	if (m_transition) {
		startValue = m_transition->currentValue().value<QColor>();
		m_transition->stop();
	}

	m_transition = new QVariantAnimation(this);

	m_transition->setStartValue(startValue);
	m_transition->setEndValue(in ? highlightColor : baseColor);
	m_transition->setDuration(m_duration);

	connect(m_transition, &QVariantAnimation::valueChanged, [this](const QVariant &value){
		m_currentColor = value.value<QColor>();
		repaint();
	});

	connect(m_transition, &QVariantAnimation::destroyed, [this](){
		m_transition = nullptr;
	});

	m_transition->start(QAbstractAnimation::DeleteWhenStopped);
}
