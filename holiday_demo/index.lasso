[
// Either load the file holiday.inc during server or site startup,
// in server or site library, or include it.  Choose one method.
// I recommend site startup.
// include('holiday.inc'); // optional loading method
]
[include('/lasso/_inc/_top.inc')]
    <p>Enter values for each field.</p>
    <p>If you leave either <em>month</em> or <em>year</em> blank, their default values will be set to the current month or year, respectively.</p>
    <p>If you check <em>Next</em>, then the next ordinal/dayofweek for the month and year will be returned.</p>

    <form method="post" action="[response_filepath]">
        <div class="row">
            <div class="large-3 columns">
                <label>ordinal
                <input type="text" name="ordinal" value="[action_param('ordinal')]" placeholder="ordinal" />
                </label>
            </div>
            <div class="large-3 columns">
                <label>dayofweek
                <input type="text" name="dayofweek" value="[action_param('dayofweek')]" placeholder="dayofweek" />
                </label>
            </div>
            <div class="large-3 columns">
                <label>month
                <input type="text" name="month" value="[action_param('month')]" placeholder="month" />
                </label>
            </div>
            <div class="large-3 columns">
                <label>year
                <input type="text" name="year" value="[action_param('year')]" placeholder="year" />
                </label>
            </div>
        </div>
        <div class="row">
            <div class="large-12 columns">
              <label></label>
              <input id="checkbox1" name="next" type="checkbox" value="true" [action_param('next') != '' ? ' checked="checked"']><label for="checkbox1">Next</label>
              </label>
            </div>
        </div>
        <input type="submit" name="submit" value="Submit" class="button" />

    </form>
[
// validate inputs
if(action_param('submit') != '');
    '<h2>';
    if(action_param('next') != '');
        holiday(
            integer(action_param('ordinal')),
            integer(action_param('dayofweek')),
            (integer(action_param('month')) != 0 ? integer(action_param('month')) | date->month),
            -next=action_param('next'));
        action_param('year') != '' ? ' (year ignored)';
    else;
        holiday(
            integer(action_param('ordinal')),
            integer(action_param('dayofweek')),
            (integer(action_param('month')) != 0 ? integer(action_param('month')) | date->month),
            (integer(action_param('year')) != 0 ? integer(action_param('year')) | date->year));
    /if;
    '</h2>';
    '<p style="color:red; font-weight:bold;">';
    error_code != 0 ? error_currenterror;
    '</p>';
/if;
]
<p>
<a href="http://www.stevepiercy.com/holiday-lasso-8-custom-tag-determines-the-nth-day-of-the-week.html">Read the article Holiday - Lasso 8 Custom Tag Determines the Nth Day of the Week</a> for more examples.
</p>
[include('/lasso/_inc/_bottom.inc')]
