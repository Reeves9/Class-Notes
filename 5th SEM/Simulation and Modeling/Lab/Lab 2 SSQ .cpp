// Lab:  2
// Simulation of Single server Queueing system 

/* External definitions for single-server queueing system. */

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include "lcgrand.h"
#define Q_LIMIT 100  /* Limit on queue length. */
#define BUSY      1  /* Mnemonics for server's being busy */
#define IDLE      0  /* and idle. */


  int   next_event_type,     // integer 1 for arrival and 2 for departure
		num_custs_delayed, 
		num_delays_required,  //total number of customers to be simulated
		num_events,         // number of events = 2
		num_in_q,          // number of customers waiting in the queue
		server_status;       //idle or busy
 
 float 	area_num_in_q,   /* total time of all customer waiting in queue upto now
 							Q(tn)=Q(tn-1)+(nq)*(tn-tn-1)
							Q(tn): Area under Q(t) current event
							Q(tn-1): Area under Q(t) of previous event
							nq: Number of customer waiting in queue at now*/
 
		area_server_status, /*total time of server busy in serving the customers 
							If server busy at the occurrence of current event then
							B(tn)=B(tn-1)+( tn-tn-1)
							B(tn): Area under B(t) of current event
							B(tn-1): Area under B(t) of previous event
							tn: time of current event (now)
							tn-1: time of previous event  */
		
		mean_interarrival, 
		mean_service,
		sim_time,       //defines the time simulation time.
		
		time_arrival[Q_LIMIT + 1], /* stores the arrival time of customers are being 
	                 	waiting in queue. The time in list, use to calculate the
						delay time before they start service.*/
						
		time_last_event, /* stores the time of event just occur at moment 
		                 whether the times are arrival or departure.*/
		                 
		time_next_event[3], //store the next arrival time and next departure time 
		
		total_of_delays;   // number of customers served at any moment

FILE  *infile, *outfile;

void  initialize(void);
void  timing(void);
void  arrive(void);
void  depart(void);
void  report(void);
void  update_time_avg_stats(void);
float expon(float mean);


main()  /* Main function. */
{
    /* Open input and output files. */

    infile  = fopen("mm1.txt",  "r");
    outfile = fopen("mm1out.txt", "w");

    
	/* Specify the number of events for the timing function. */
    num_events = 2;   // Arrival and Departure

    /* Read input parameters. */
    fscanf(infile, "%f %f %d", &mean_interarrival, &mean_service,&num_delays_required);

    /* Write report heading and input parameters. */

    fprintf(outfile, "\t\t Single-server queueing system\n\n");
    fprintf(outfile, "Mean interarrival time%10.3f minutes\n\n",mean_interarrival);
    fprintf(outfile, "Mean service time%15.3f minutes\n\n", mean_service);
    fprintf(outfile, "Number of customers%12d\n\n", num_delays_required);

    /* Initialize the simulation. */

    initialize();

    /* Run the simulation while more delays are still needed. */
   
    while (num_custs_delayed < num_delays_required)     
    {
        /* Determine the next event. */
        timing();

        /* Update time-average statistical accumulators. */
        update_time_avg_stats();

        /* Invoke the appropriate event function. */
        switch (next_event_type) 
        {
            case 1:
                arrive();
                break;
            case 2:
                depart();
                break;
        }
    }

    /* Invoke the report generator and end the simulation. */

    report();

    fclose(infile);
    fclose(outfile);

    return 0;
}


void initialize(void)  /* Initialization function. */
{
   
    /* Initialize the simulation clock. */
    sim_time = 0.0; 

   /* Initialize the state variables. */
    server_status   = IDLE;   
    num_in_q        = 0;    // number of customers in queue
    time_last_event = 0.0;    // time in simulation clock

    /* Initialize the statistical counters. */
    num_custs_delayed  = 0;  // total customers served
    total_of_delays    = 0.0; //
    area_num_in_q      = 0.0;   // total time queue for all customers
    area_server_status = 0.0;   // total server busy time

    /* Initialize event list.  Since no customers are present, the departure
       (service completion) event is eliminated from consideration. */
    time_next_event[1] = sim_time + expon(mean_interarrival); /* first customer will 
	                                                 arrive at this time */
    time_next_event[2] =   9999;    //  initialized to infinity
}


void timing(void)  /* Timing function. */
{
    int   i;
    float min_time_next_event =  9998;  // high value 
    next_event_type = 0;
    /* next_event_type =1    : Arrival
      next_event_type = 2    : Departure */

    /* Determine the event type of the next event to occur. */
    for (i = 1; i <= num_events; ++i)
        if (time_next_event[i] < min_time_next_event)
        {   
            min_time_next_event = time_next_event[i];
            next_event_type     = i;
        }

    /* Check to see whether the event list is empty. */
    if (next_event_type == 0)
    {
        /* The event list is empty, so stop the simulation. */
        fprintf(outfile, "\nEvent list empty at time %f", sim_time);
        exit(1);
    }
  
   /* The event list is not empty, so advance the simulation clock. */
    sim_time = min_time_next_event;
 }


void arrive(void)  /* Arrival event function. */
{
    float delay;

    /* Schedule next arrival. */

    time_next_event[1] = sim_time + expon(mean_interarrival);
	fprintf(outfile,"\t : %f",time_next_event[1]);
	
    /* Check to see whether server is busy. */

    if (server_status == BUSY)
    {
        /* Server is busy, so increment number of customers in queue. */

        ++num_in_q;

        /* Check to see whether an overflow condition exists. */

        if (num_in_q > Q_LIMIT)
        {
            /* The queue has overflowed, so stop the simulation. */

            fprintf(outfile, "\nOverflow of the array time_arrival at");
            fprintf(outfile, " time %f", sim_time);
            exit(1);
        }

        /* There is still room in the queue, so store the time of arrival of the
           arriving customer at the (new) end of time_arrival. */

        time_arrival[num_in_q] = sim_time;
    }

    else
    {
        /* Server is idle, so arriving customer has a delay of zero.  (The
           following two statements are for program clarity and do not affect
           the results of the simulation.) */

        delay            = 0.0;
        total_of_delays += delay;

        /* Increment the number of customers delayed, and make server busy. */

        ++num_custs_delayed;
        server_status = BUSY;

        /* Schedule a departure (service completion). */

        time_next_event[2] = sim_time + expon(mean_service);
    }
}


void depart(void)  /* Departure event function. */
{
    int   i;
    float delay;

    /* Check to see whether the queue is empty. */

    if (num_in_q == 0)
    {
        /* The queue is empty so make the server idle and eliminate the
           departure (service completion) event from consideration. */

        server_status      = IDLE;
        time_next_event[2] =  9999; //1.0e+30;
    }

    else
    {
        /* The queue is nonempty, so decrement the number of customers in
           queue. */

        --num_in_q;

        /* Compute the delay of the customer who is beginning service and update
           the total delay accumulator. */

        delay            = sim_time - time_arrival[1];
        total_of_delays += delay;

        /* Increment the number of customers delayed, and schedule departure. */

        ++num_custs_delayed;
        time_next_event[2] = sim_time + expon(mean_service);

        /* Move each customer in queue (if any) up one place. */

        for (i = 1; i <= num_in_q; ++i)
            time_arrival[i] = time_arrival[i + 1];
    }
}


void report(void)  /* Report generator function. */
{
    /* Compute and write estimates of desired measures of performance. */

    fprintf(outfile, "\n\nAverage delay in queue%11.3f minutes\n\n",
            total_of_delays / num_custs_delayed);
    fprintf(outfile, "Average number in queue%10.3f\n\n",
            area_num_in_q / sim_time);
    fprintf(outfile, "Server utilization%15.3f\n\n",
            area_server_status / sim_time);
    fprintf(outfile, "Time simulation ended%12.3f minutes", sim_time);
}


void update_time_avg_stats(void)  /* Update area accumulators for time-average
                                     statistics. */
{
    float time_since_last_event;

    /* Compute time since last event, and update last-event-time marker. */
    time_since_last_event = sim_time - time_last_event;
    time_last_event       = sim_time;

    /* Update total time in queue */
    area_num_in_q      += num_in_q * time_since_last_event;
    
    /* Update area under server-busy indicator function. */
    area_server_status += server_status * time_since_last_event;
 }


float expon(float mean)  /* Exponential variate generation function. */
{
    /* Return an exponential random variate with mean "mean". */
    return -mean * log(lcgrand(1)); 
	// log returns natural logarithm of input parameter
}


