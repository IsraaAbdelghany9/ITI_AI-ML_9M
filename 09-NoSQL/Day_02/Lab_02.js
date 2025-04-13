// Q1. Provide the MongoDB code for enforcing JSON schema validation
// when creating a collection named "employees" with required fields:
// "name," 
// "age" (min. 18), 
// and "department" (limited to ["HR," "Engineering," "Finance"]). 

use Stuff
db.createCollection("employees",
{
    validator:{
        "$jsonSchema":
        {
            "bsonType": "object",
            "title": "Employee Required Data ",
            "required": ["name" ,"age" , "department"],
            
            "properties":{
               // name properties
               "name" : 
               {
                  "bsonType": "string",
                  "description" : "must be a string and is required"
               },
                      
               // "age" (min. 18)
                "age":
                {
                    "bsonType":"int",
                    "minimum": 18,
                    "description": "must be an integer and at least 18"
                },
                
               //"department" (limited to ["HR," "Engineering," "Finance"]). 
                department:
                {
                    "bsonType":"string",
                    "enum" : ["HR", "Engineering" ,"Finance"],
                    "description" : "The department data should be in HR, Engineering, Finance values"
                }
            }
        }     
    }   
})

// Q.2 Find documents where the "tags" field exists. 
db.inventory.find({"tags":{$exists:true}})


// Q3. Find documents where the 
// "status" field has a value in [A, B] using both the `$in` , `$or` operators. 

db.inventory.find({"status":{$in: ['A', 'B']}})
db.inventory.find({$or: [{ status: "A" },{ status: "B" }]});


// Q.4 Find documents where the "tags" field does not contain values "ssl" or "security." 
db.inventory.find({"tags":{$nin:["ssl",  "security" ]}})


// Q.5 Find documents where the "qty" field is equal to 85. 
db.inventory.find({"qty":{$eq:85}})


// Q.6 Find documents where
// the "tags" array contains all of the values [ssl, security] using the `$all` operator
db.inventory.find({"tags":{$all:["ssl",  "security" ]}})


// Q.7 Find documents where the "tags" array has a size of 3. 
db.inventory.find({"tags":{$size:3}})


// Q.8 Find documents where the "tags" field is of type array. 
db.inventory.find({"tags":{$type:'array'}})


// Q9. Update the "item" field in the "paper" document,
// setting "size.uom" to "meter" and using the `$currentDate` operator. 
db.inventory.updateOne(
    // Non
    { item: "paper" },
    {
        $set: { "size.uom": "meter" },
        $currentDate: { lastModified: true }, 
    },
);

// a. Also, use the upsert option and change filter condition item:”paper”. 
db.employees.updateOne( 
    // given error because of the required fields missing
    { item: "paper" },
    {
        $set: { "size.uom": "meter" },
        $currentDate: { lastModified: true }, 
    },
    { upsert: true }
);


// b. Use the `$setOnInsert` operator. 
db.inventory.updateOne(
    { item: "paper" },
    {
        $set: { "size.uom": "meter" },
        $currentDate: {lastModified: true }, 
        // $setOnInsert: {name: "israa", "age": 23, "department": "HR", createdBy: "Israa"}
        $setOnInsert: {createdBy: "Israa"}
    },
    { upsert: true }
);


// c. Try `updateOne`, `updateMany`, and `replaceOne`. 
db.inventory.updateOne(
    { item: "paper" },
    {
        $set: { "size.uom": "meter" },
        $currentDate: { lastModified: true }, 
        $setOnInsert: {createdBy: "Israa"}
    },
    { upsert: true }
);

// created another one
db.inventory.updateMany(
    { item: "paper" },
    {
        $set: { "size.uom": "meter" },
        $currentDate: { lastModified: true }, 
        $setOnInsert: {createdBy: "Israa"}
    },
    { upsert: true }
);


db.inventory.replaceOne(
    { item: "paper" },
    {
        // it gave an error because it is an atomic properties
        //$set: { "size.uom": "meter" },
        //$currentDate: { lastModified: true }, 
        //$setOnInsert: {createdBy: "Israa"}
        replaced: "true"
    },
    { upsert: true }
);



// Q.10 Insert a document with incorrect field names "neme" and "ege," then rename them to "name" and "age." 
db.inventory.insertOne({
    neme: "Israa",
    ege: 24
});

db.inventory.find({neme : "Israa"})

db.inventory.updateOne(
    // you should apply condition with the updateOne
    {neme : "Israa"}, 
    {
        $rename: {
            "neme": "name",
            "ege": "age"
        }
    }
);
db.inventory.find({name : "Israa"})


// Q.11 Try to reset any document field using the `$unset` function. 
db.inventory.updateOne(
    { name: "Israa" }, 
    {
        $unset: { age: "" }
    }
);

db.inventory.find({name : "Israa"})


// Q.12 Try update operators like `$inc`, `$min`, `$max`, and `$mul` to modify document fields. 
db.inventory.insertOne({
    name: "Ahmed",
    age: 24,
    salary: 5000
});

db.inventory.updateOne(
    { name: "Ahmed" },
    { $inc: { age: 1 } }
);

db.inventory.find({name : "Ahmed"})

db.inventory.updateOne(
    { name: "Ahmed" },
    { $min: { salary: 4000 } }
);

db.inventory.find({name : "Ahmed"})

db.inventory.updateOne(
    { name: "Ahmed" },
    { $max: { salary: 10000 } }
);

db.inventory.find({name : "Ahmed"})

 