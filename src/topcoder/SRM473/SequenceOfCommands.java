import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;


/*
 *  there arte three cases 
 * 
 * 
 */

public class SequenceOfCommands
{

	public String whatHappens(String[] commands)
	{
		int dx[] ={ 1,0,-1,0} ;
		int dy[] = {0,-1,0,1} ;
		int x= 0,y = 0,dir = 0 ; 

		for(int i = 0 ; i < 4 ; ++i)
		{
			for(int j = 0 ; j<commands.length ; j++)
			{
				int size = commands[j].length() ;
				for(int k = 0 ; k < size ;++k)
				{
					switch(commands[j].charAt(k))
					{
					case 'S':
						x += dx[dir] ;
						y += dy[dir] ;

						break ;
					case 'L' :
						dir = (dir+3) %  4 ;
						break ;
					case  'R' : 
						dir = (dir + 1) % 4 ;
						break ; 			          
					}
				}
			}
		} 

		if(x==0 && y==0)
		{
			return "bounded";
		}
		else
		{
			return "unbounded";
		}

	}


}
//Powered by [KawigiEdit] 2.0!
