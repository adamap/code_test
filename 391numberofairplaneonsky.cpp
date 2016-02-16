//Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?
//
//
//For interval list [[1,10],[2,3],[5,8],[4,7]], return 3
//
//Note 
//
//If landing and flying happens at the same time, we consider landing should happen at first.



/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
 
struct comparator{
    
    bool operator() (Interval a, Interval b)
    {
        return (a.start < b.start);
    }
}; 
 
//O(n^2) 
int countOfAirplanes_pwrn(vector<Interval> &airplanes)
{
    if ( airplanes.size() == 0)
    {
        return 0;
    }
    sort(airplanes.begin(), airplanes.end(), comparator());
        
    int max = 1;
    
    
    int i = 0;
    Interval cur = airplanes[i];
            
    vector<int> end_time;
    end_time.push_back(cur.end);
    for ( int j = i+1; j < airplanes.size(); j++)
    {
        int count = 1;
        
        for (int k = 0; k < end_time.size(); k++)
        {
            if (airplanes[j].start < end_time[k] )
            {
                count++;
            }
        }
                
        if ( count > max)
        {
            max = count;
        }
        end_time.push_back(airplanes[j].end);
    }
    return max;
}

struct point
{
    int time;
    int isflying;
    
    point(int s, int i):time(s),isflying(i)
    {
        
    }
};
struct comparator1 {

  bool operator() (point *a, point *b)
  {
    if (a->time != b->time)
    {
      return (a->time < b->time);
    }
    else
    {
      return (a->isflying < b->isflying);
    }
  }
}; 

int countOfAirplanes_scan(vector<Interval> &airplanes)
{
    if ( 0 == airplanes.size())
    {
        return 0;
    }
        
    vector<point *>p;
    
    for (int i = 0; i < airplanes.size(); i++)
    {
        p.push_back(new point(airplanes[i].start, 1));
        p.push_back(new point(airplanes[i].end, 0));
    }
        
    sort(p.begin(), p.end(), comparator1());
    
    int count = 0;
    int max = INT_MIN;
    for ( int i = 0; i < p.size(); i++)
    {
        if (p[i]->isflying == 1)
        {
            count++;
        }
        else
        {
            count--;
        }
        if ( count > max)
        {
            max = count;
        }
    }
    return max;
}

int countAirplanes_scan(vector<Interval> &airplanes);

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) 
    {
        // write your code here
        //return countOfAirplanes_scan(airplanes);
        //return  countOfAirplanes_pwrn(airplanes);
        return countAirplanes_scan(airplanes);
    }
};

struct pointp
{
  int time;
  int flying;

  pointp(int i, int j)
  {
    time = i;
    flying = j;
  }
};

struct comparator_ca
{
  bool operator()(pointp *a, pointp *b)
  {
    if (a->time != b->time)
    {
      return (a->time < b->time);
    }
    else
    {
      return (a->flying < b->flying);
    }
  }
};



int countAirplanes_scan(vector<Interval> &airplanes)
{
  if (0 == airplanes.size())
  {
    return 0;
  }

  vector<pointp *>flyingcount;

  for (int i = 0; i < airplanes.size(); i++)
  {
    flyingcount.push_back(new pointp(airplanes[i].start, 1));
    flyingcount.push_back(new pointp(airplanes[i].end, 0));
  }

  sort(flyingcount.begin(), flyingcount.end(), comparator_ca());

  int count = 0;
  int maxcount = INT_MIN;
  for (int i = 0; i < flyingcount.size(); i++)
  {
    if (flyingcount[i]->flying == 1)
    {
      count++;
    }
    else
    {
      count--;
    }

    if (count > maxcount)
    {
      maxcount = count;
    }
  }

  return maxcount;
}






























