SNL Stocks
==========

This module provides an API wrapper to the SNL Stocks Stock Quote service. It
will retrieve and cache the results from the Stock Quote service for any given
stock IID.

Results are cached for 15 minutes (requires properly configured cron job).

Usage
-----

Install and enable the module like any other. Once the module is installed, the
`snlstocks_request()` is available.

###Parameters

**Integer $IID:** the IID of the stock to process. SNL should be able to
provide the IID. E.g. Atlantic Power is 4098671.

**Boolean $reset:** Whether or not to force a cache refresh. Items will be
returned from the cache if the cache isn't stale unless this is set to TRUE.

**String $url:** The URL to make the request to. I doubt this will change.

###Return value

Object|FALSE An array of stock quote items or FALSE on failure.

Example Output
--------------

    (Object) stdClass
      ->QuoteTimeStamp (String, 19 characters ) 2014-03-04T00:00:00
      ->CurrentPrice (String, 4 characters ) 3.01
      ->NetChangeFromPreviousClose (String, 4 characters ) 0.11
      ->PercentChangeFromPreviousClose (String, 4 characters ) 3.79
      ->VolumeMostRecent (String, 6 characters ) 856671
      ->OneYearAvgDailyVolume (String, 6 characters ) 451436
      ->HighestSalePriceMostRecent (String, 4 characters ) 3.03
      ->LowestSalePriceMostRecent (String, 4 characters ) 2.93
      ->FiftyTwoWeekHigh (String, 4 characters ) 5.96
      ->FiftyTwoWeekLow (String, 4 characters ) 2.35
      ->MarketValueAtCurrentPrice (String, 12 characters ) 362042191.98
      ->LastClose (String, 3 characters ) 2.9
      ->ResultMessage (String, 2 characters ) OK
      ->DividendYield (String, 5 characters ) 13.29
      ->RowCount (String, 1 characters ) 1
      ->SharesOutstanding (String, 9 characters ) 120279798

