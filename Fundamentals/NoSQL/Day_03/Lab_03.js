// Lab_03

// Q1. Try Export any Collection and import it into new Collection using Robo 3T 
// I have exported the inventory json file in Day03 folder
// I have imported it into AI 


// Q2. Calculate the total revenue for product from sales collection documents 
// within the date range '01-01-2020' to '01-01-2023' 
// and then sort them in descending order by total revenue. 

// Total Revenue=  Sum (Quantity * Price) 

use Stuff

db.sales.find({}) // To visualize data first

db.sales.aggregate([

                    {
                        // match stage -> within the date range '01-01-2020' to '01-01-2023'
                        $match :
                        {
                            "date": { $gte: ISODate( "2020-01-01" ), $lte: ISODate( "2023-01-01" ) }
                        }
                    },
                    {
                        // Group stage -> total revenue , id for product
                        // Total Revenue=  Sum (Quantity * Price) 
                        $group:
                        {
                            _id: "$product",
                            totalOrderValue: { $sum: { $multiply: [ "$price", "$quantity" ] } }
                        }
                    },
                    {
                        // Sort stage -> dec (-1) by total revenue. 
                        $sort: 
                        { 
                            totalOrderValue: -1 
                        }
                    }

])



// Q3. Try Query 2 using Robo 3T using aggregate wizard 
// and insert result into new collection 
// named “newColl” 

db.sales.aggregate([
                    {
                        // match stage -> within the date range '01-01-2020' to '01-01-2023'
                        $match: 
                        {
                            "date": { $gte: ISODate("2020-01-01"), $lte: ISODate("2023-01-01") }
                        }
                    },
                    {
                        // Group stage -> total revenue , id for product
                        // Total Revenue=  Sum (Quantity * Price)
                        $group: 
                        {
                            _id: "$product",
                            totalOrderValue: { $sum: { $multiply: [ "$price", "$quantity" ] } }
                        }
                    },
                    {
                        // Sort stage -> dec (-1) by total revenue. 
                        $sort: 
                        { 
                            totalOrderValue: -1 
                        }
                    },
                    {
                        // Output stage -> save in new collection "newColl"
                        $out: "newColl"  // Store results in "newColl"
                    }
])

show collections // To ensure new collection


// Q4.Calculate the average salary for employees for each department from the employee’s collection. 

db.employee.insertMany([
    { department: "Engineering", salary: 75000 },
    { department: "Marketing", salary: 60000 },
    { department: "HR", salary: 50000 }
])

db.employee.find({})

db.employee.aggregate([
                        // match stage -> No match 
                    {
                        // Group stage ->  average salary , department
                        $group: 
                        {
                            _id: "$department",
                            avgValue: { $avg: "$salary"}
                        }
                    },
                   
])


// Q5. Use likes Collection to calculate max and min likes per title 

db.likes.find({})

db.likes.aggregate([
                        // match stage -> No match 
                    {
                        // Group stage ->  max & min likes , title
                        $group: 
                        {
                            _id: "$title",
                            maxVal: { $max : "$likes"},
                            minVal: { $min : "$likes"},
                        }
                    },
                   
])


// Q6. Get inventory collection Count , countDocuments 

db.inventory.count()

db.inventory.countDocuments({})


// Q7. Display 5 documents only from inventory collection 

db.inventory.find({}).limit(5)


// Q8.Count numbers of large Pizza size 
// from orders collection  
// [using $count inside aggregate function] 

db.orders.find({})    

db.orders.aggregate([
                    {
                        // match stage -> large Pizza size 
                        $match: { size: "large" } 
                    },

                    {
                        // Count stage -> count number of large pizzas
                        // _id : "$name",
                        $count: "largePizzaCount"  
                    }
])

