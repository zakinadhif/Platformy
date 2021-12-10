#pragma once

#include "UI/Widget.hpp"

class Container : public Widget
{
public:
	typedef std::shared_ptr<Container> Ptr;
	typedef std::shared_ptr<const Container> ConstPtr;

	void add(Widget::Ptr widget, const std::string& name);
	void remove(const std::string& name);

	Widget::Ptr get(const std::string& name);
	Widget::ConstPtr get(const std::string& name) const;

	bool isContainer() const override;

	Widget::Ptr getWidgetBelowPosition(sf::Vector2f position) const;

protected:
	std::unordered_map<std::string, Widget::Ptr> m_subwidgets;
};

inline bool Container::isContainer() const
{
	return true;
}
