Holiday - Lasso 8 Custom Tag Determines the Nth Day of the Week
###############################################################

Read the article `Holiday - Lasso 8 Custom Tag Determines the Nth Day of
the Week
<http://www.stevepiercy.com/holiday-lasso-8-custom-tag-determines-the-nth-day-of-the-week.html>`_.

Description
===========

``[holiday]`` determines the Nth day of the week for a given month and year,
and optionally returns the next occurrence. Also returns an error in case
invalid parameters are submitted, which can be displayed by
``[error_currenterror]``. The defaults for month and year are the current
month and year. This tag is handy for determining when holidays fall on a
calendar. Requires the custom tag `lp_date_leapyear
<http://www.lassosoft.com/tagswap/detail/lp_date_leapyear>`_.

``[holiday]`` accepts up to five parameters.

``-ordinal`` is required, and of type integer. Valid values are 1=first, ...,
5=fifth, -1=last, and correspond with the ordinal day of the month.

``-dayofweek`` is required, and of type integer. Valid values are 1=Sunday,
..., 7=Saturday.

``-month`` is optional, and of type integer. Valid values are 1 - 12,
corresponding to the number of the month. Default is current month.

``-year`` is optional, and of type integer. Valid values are 1000 - 9999.
Default is current year.

``-next`` is optional and can be any type. If present, ``holiday`` returns the
next occurrence of the ordinal dayofweek for the month and year.

Usage
=====

The following two statements are equivalent.

.. code-block:: lasso

    [holiday(-ordinal=-1, -dayofweek=2, -month=5, -year=2009)]
    [holiday(-1,2,5,2009)]

The following two statements are equivalent.

.. code-block:: lasso

    [holiday(-ordinal=-1, -dayofweek=2, -month=5, -next)]
    [holiday(-1,2,5,-next)]

Example Holidays
================

Martin Luther King, Jr. Day (third Monday of January)

.. code-block:: lasso

    [holiday(3,2,1,year)]

Presidents Day (third Monday of February)

.. code-block:: lasso

    [holiday(3,2,2,year)]

Daylight Savings time begins (second Sunday of March)

.. code-block:: lasso

    [holiday(2,1,3,year)]

Mothers Day (second Sunday of May)

.. code-block:: lasso

    [holiday(2,1,5,year)]

Memorial Day (last Monday of May)

.. code-block:: lasso

    [holiday(-1,2,5,year)]

Fathers Day (you get the idea)

.. code-block:: lasso

    [holiday(3,1,6,year)]

Labor Day

.. code-block:: lasso

    [holiday(1,2,9,year)]

Columbus Day

.. code-block:: lasso

    [holiday(2,2,10,year)]

Daylight Savings Time ends

.. code-block:: lasso

    [holiday(1,1,11,year)]

Thanksgiving Day

.. code-block:: lasso

    [holiday(4,5,11,year)]

Acknowledgments
===============

``[holiday]`` is based on an `idea from IRT
<http://www.irt.org/articles/js050/>`_.

With suggestions for improvement from `Bil Corry
<https://twitter.com/bilcorry>`_.

Inspired by `jQuery Datepicker <http://keith-wood.name/datepick.html>`_.
