#include"sort.h"
#include"randomArray.h"
#include<iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

using namespace algorithm::sort;
using namespace std;

int main()
{
	//randomArray m_randomArray;
	//m_randomArray.myTest();
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
	log4cpp::PatternLayout *pLayout = new log4cpp::PatternLayout();
	pLayout->setConversionPattern("%d{%Y/%m/%d,%H:%M:%S} -- %p %c: %m%n");
	osAppender->setLayout(pLayout);
	//log4cpp::Category& root = log4cpp::Category::getRoot();
	log4cpp::Category& root =log4cpp::Category::getInstance("myTest");
	root.addAppender(osAppender);
	root.setPriority(log4cpp::Priority::DEBUG);
	root.error("Hello log4cpp in a Error Message!");
	root.warn("Hello log4cpp in a Warning Message!");
	log4cpp::Category::shutdown();  
	
	return 0;
}