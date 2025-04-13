// Q1. Create new Database named Demo 
// collections named trainningCenter1 , trainningCenter2  
// NOTE: trainningCenter2 will apply all quires. 

use Demo

db.createCollection("trainningCenter1")
db.createCollection("trainningCenter2")


// Q2. Insert documents into trainningCenter1 collection contains :
// _id , 
// name as firstName lastName ,
// age , 
// address as array ,
// status 
// Using Variable (Array Data) and insert ONE 


var data1 = [
            {
                _id: 1,
                name: { firstName: "Israa", lastName: "Abdelghany" },
                age: 24,
                address: ["Bokhary Street", "Mansoura", "Egypt"],
                status: "active"
            },
            {
                _id: 2,
                name: { firstName: "Mohamed", lastName: "Abdelghany" },
                age: 28,
                address: ["Cairo Street", "Giza", "Egypt"],
                status: "active"
            }
            ]
            
db.trainningCenter1.insertOne(data1) // It has added the first one only

db.trainningCenter1.find({})

// Q3. Insert documents into trainningCenter2 collection  

// Using Same Variable (Array Data) with same data and insert MANY 

db.trainningCenter2.insertMany(data1)

db.trainningCenter2.find({})



// Q4. Use find. explain function (find by age field) and mention scanning type 

db.trainningCenter1.find({age : 24}).explain() // COLLSCAN

db.trainningCenter2.find({age : 24}).explain() // COLLSCAN


// Q5. Create index on created collection named it “IX_age” on age field   
// Mixed with Q6. Create index on created collection named it “IX_age” on age field  
// Use find. explain view winning plan for index created (find by age field) and mention scanning type 

db.trainningCenter1.createIndex({ age: 24 }, { name: "IX_age" })
db.trainningCenter1.find({age : 24}).explain() // IXSCAN

db.trainningCenter2.createIndex({ age: 28 }, { name: "IX_age" })
db.trainningCenter2.find({age : 24}).explain() // IXSCAN .. not only the 28 ,, the whole column (field)



// Q7. Create index on created collection named it “compound” on firstNsme and lastName 
// Try find().explain before create index and mention scanning type 
// Try find().explain after create index and mention scanning type 

db.trainningCenter2.find({ "name.firstName": "Israa", "name.lastName": "Abdelghany" }).explain() // winningPlan, stage: 'COLLSCAN

db.trainningCenter2.createIndex({ "name.firstName": 1, "name.lastName": 1 }, { name: "compoundName" })

//winningPlan: {
//      isCached: false,
//      stage: 'FETCH',
//      inputStage: {
//        stage: 'IXSCAN',

db.trainningCenter2.find({ "name.firstName": "Israa", "name.lastName": "Abdelghany" }).explain()

db.trainningCenter2.find({ "name.firstName": "Israa" }).explain() // IXSCAN

db.trainningCenter2.find({ "name.lastName": "Abdelghany" }).explain() // COLLSCAN

db.trainningCenter2.find({ "name.lastName": "Abdelghany", "name.firstName": "Israa" }).explain() // IXSCAN



// Q8. Try to delete from your collection where _id = 5 [insert it if not exists] 


// First normal way 
db.trainningCenter2.insertOne({
    _id: 5,
    name: { firstName: "Ali", lastName: "Hassan" },
    age: 30,
    address: ["Street 10", "Cairo", "Egypt"],
    status: "inactive"
})


// better solution -> if not exist add it not just add it 
db.trainningCenter2.updateOne(
    { _id: 5 },  
    { 
        $set: { 
            name: { firstName: "Ali", lastName: "Hassan" }, 
            age: 30, 
            address: ["Street 10", "Cairo", "Egypt"], 
            status: "inactive" 
        } 
    },  
    { upsert: true }  // Inserts if not exists
)


db.trainningCenter2.deleteOne({ _id: 5 })



// Q9. Delete all documents from the trainingCenter collection. 

db.trainningCenter2.deleteMany({})


// Q10. Drop the database and confirm its removal. Which command do you use to ensure the deletion? 

db.dropDatabase()

show dbs // Done successfully 


// Q11. Backup your Labs database (Mongo_ITI)  

db.serverCmdLineOpts() // To get the paths to storage , log ... etc

// sudo chmod -R 777 /var/lib/mongodb
// mongodump --db Stuff --out "/var/lib/mongodb"
// ls /var/lib/mongodb 
// you will find Stuff in it 


// Q12. Restore the taken back-up by new DB name Called Mongo_ITI_New 

// mongorestore --db Mongo_ITI_New --dir "/var/lib/mongodb/Stuff"
