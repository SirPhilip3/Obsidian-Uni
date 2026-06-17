---
publish: true
---
*Web crawling* is the process of locating, fetching and storing the pages available on the web 

Hyperlink structure of the web is called the *web graph*

Basic Crawling :
1. Begin with **seed** URLs
2. Fetch and parse them
	1. Extract URLs they point to
	2. Put them in a queue
>[!note] 
>Remove URLs already present in the queue
3. Fetch each URL on the queue and repeat

>[!warning] 
>1. It's not feasible with one machine 
>2. There are *malicious pages*
>	1. *Spam pages*
>	2. *Spider traps* forces infinite number of fetches

Also crawler should :
+ should not crawl duplicate pages
+ be *polite* : do not hit a server too often and follow admin rules

>[!note] Robots.txt
>Formatted documents that says what can be crawled and what not in a given domain
>
>>[!example] 
>>```
>>User-agent: *
>>Disallow: /yoursite/temp/
>>
>>User-agent: searchengine
>>Disallow:
>>```
>>
>>No robot should visit `/yoursite/temp/` except the one called *searchengine*
>>

What crawlers **should** do : 
+ be capable of *distributed* operation
+ be *scalable*
+ *efficent*
+ Fetch pages of high quality first
+ *continuos* operation : continue fetching previously fetched pages to update it
+ *extensible*

**URL frontier** is the queue that we build while crawling a page

## DNS

Given a URL returns an IP

DNS is blocking , one request at a time , solution :
+ DNS chaching
+ batch DNS resolver , collects query and than executes them together

## URL normalization / canonization

Some links may be relative to the page we are on , this need to be modified into an absolute URL 

>[!example] 
>http://en.wikipedia.org/wiki/Main_Page has a relative link to /wiki/Wikipedia:General_disclaimer which we transform into the absolute URL http://en.wikipedia.org/wiki/wiki/Wikipedia:General_disclaimer

## Duplicate pages

If we have already seen a page we should not re-fect it , this is done by computing *fingerprints* or *shingles* 

Some duplicates depends on the URL that has added to it some sessoinds or other parameters while being the same page they will have a different URL 

## Filters and robots.txt

Once a *robots.txt* is fetched for a domain we need to *cache* it for the various pages of that domain

## Distributed Implementation 

Partition the *URL* to crawl between various machines , to partition we may use :
+ **hashing** that returns the id of the machine to send it to
+ **site-based** where all the pages of a given domain are assigned to a single machine

>[!warning] 
>*hash-based partitioning* may cause politness inconsistencies between same domain pages 

>[!note] Fault Tolerance
>When a node dies the URL need to be redistributed between the remaining nodes


The duplicate URL eliminator must recieve the URLs fetched by the other machine in order to deduplicate them ( lot's of *communications* need to happend in the system leading to slower performances )

### Reduce communications in the system

+ **Firewall mode** 
The URL space is partitioned among crawlers 
The crawlers do not communicate links falling into other crawlers space 

>[!warning] 
>Some URL may never be crawled 

+ **Crossover mode**
The same as before but the crawlers always follow the links when they are discovered
This may lead to duplicate crawling 

+ **Exchange mode**
Crawler communicate the links to theyr owners

>[!note] 
>We should craw some pages more times then other so that we have updated infromation about them like news 

*Politeness* : simply set a timer 

## Continuos crawling

Two separate queue : 
+ discovery queue
	+ Download pages not previously indexed 
+ refershing queue
	+ increases the *freshness* of the repository

>[!warning]
>Chaching a page means that the client must periodically poll a page in order to get the changes

+ We must keep the *number* of fresh pages as high as possible 
+ Keeping the *age* as low as possible 

When should we update the cache : 
+ *uniform* : regardless of rate of changes
+ *proportional* : more often if pages change frequenlty

>[!note] 
>We can have more than one refreshing queue depending on the frequency of the refreshes

For *unlinked* pages we forcefully need a repository of known URL's

For *dynamic* pages the crawler can submit domain specific queries 