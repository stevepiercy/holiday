[
/*
[holiday] by Steve Piercy
http://www.stevepiercy.com/holiday-lasso-8-custom-tag-determines-the-nth-day-of-the-week.html
v 1.0 released on the [holiday(1,7,11,2009)] (Use this tag to find what is that date.)
*/

define_tag('leapyear',-required='year', -type='integer',
    -description='Determines whether a given year is a leap year.  Returns either TRUE or FALSE.');
    #year%4 ? return (false);
    #year%100 ? return (true);
    #year%400 ? return (false);
    return (true);
/define_tag;

define_tag('holiday',
    -required='ordinal', -type='integer', // 1=first, ..., 5=fifth, -1=last
    -required='dayofweek', -type='integer', // 1=Sunday, ..., 7=Saturday
    -optional='month', -type='integer', // number of month, default is current month
    -optional='year', -type='integer', // default is current year
    -optional='next', // returns the next occurrence
    -description='[holiday] determines the Nth day of the week for a given month and year, and optionally returns the next occurrence.  Also returns an error in case invalid parameters are submitted, which can be displayed by [error_currenterror].  The defaults for month and year are the current month and year.  This tag is handy for determining when holidays fall on a calendar.  Requires the custom tag [leapyear].');

    // avoid submission of conflicting or invalid parameters
    if(local_defined('year') && local_defined('next'));
        error_seterrormessage('Syntax error calling tag "holiday" with conflicting parameters.  Only one of -year or -next parameters may be defined.');
        error_seterrorcode(-9900);
        return;
    /if;

    if(array(-1,1,2,3,4,5)!>>#ordinal);
        error_seterrormessage('Syntax error calling tag "holiday" with invalid parameter (-ordinal=' + #ordinal + ').  Valid values are -1, 1, 2, 3, 4, or 5.');
        error_seterrorcode(-9900);
        return;
    /if;

    if(series(1,7)!>>#dayofweek);
        error_seterrormessage('Syntax error calling tag "holiday" with invalid parameter (-dayofweek=' + #dayofweek + ').  Valid values are between 1 and 7.');
        error_seterrorcode(-9900);
        return;
    /if;

    if(local_defined('month'));
        if(series(1,12)!>>#month);
            error_seterrormessage('Syntax error calling tag "holiday" with invalid parameter (-month=' + #month + ').  Valid values are between 1 and 12.');
            error_seterrorcode(-9900);
            return;
        /if;
    /if;

    if(local_defined('year'));
        if(#year<1000 || #year>9999);
            error_seterrormessage('Syntax error calling tag "holiday" with invalid parameter (-year=' + #year + ').  Valid values are between 1000 and 9999.');
            error_seterrorcode(-9900);
            return;
        /if;
    /if;


    !local_defined('month') ? local('month') = date->month;
    !local_defined('year') ? local('year') = date->year;
    local_defined('next') ? local('next') = true | local('next') = false;

    // set days per month
    if(leapyear(#year));
        local('dayspermonth' = array(31,29,31,30,31,30,31,31,30,31,30,31));
    else;
        local('dayspermonth' = array(31,28,31,30,31,30,31,31,30,31,30,31));
    /if;

    if(#ordinal > 0);
        // get first day of the month
        local('date') = date(-month=#month, -day=1, -year=#year, -hour=12);
        // find first instance of dayofweek in the month
        local('delta') = #dayofweek - #date->dayofweek;
        if(#delta < 0);
            #delta += 7;
        /if;
        #date->add(-day=#delta);
        // adjust date to desired instance
        #date->add(-day=7 * (#ordinal - 1));
    else;
        // get last day of the month
        local('date') = date(-month=#month, -day=#dayspermonth->get(#month), -year=#year, -hour=12);
        // find last instance of dayofweek in the month
        local('delta') = #date->dayofweek - #dayofweek;
        if(#delta < 0);
            #delta += 7;
        /if;
        #date->subtract(-day=#delta);
    /if;

    // adjust to next date
    if(#next && date>=#date);
        #date->add(-year=1);
        return(holiday(#ordinal,#dayofweek,#month,#date->year));
    /if;
    return(#date);
/define_tag;
]
