// LAB_1

//1. Create a Collection named "Staff". 
use Stuff

//2. Insert one document into the "Staff" collection: {_id, name, age, gender, department}. 
db.lab.insertOne({_id:91125 , name:"Israa" , age:24 , gender:"female" , department:"AI"})

//3. Insert many documents into the "Staff" collection: 
//   Object: {_id, name, age: 20, gender: "male", department} 
//
//   Object: {_id, name, age: 25, gender: "female", managerName, department} 
//
//   Object: {_id, name, age: 15, gender, DOB} 

db.lab.insertMany([
    { _id: 1, name: "Ibrahim", age: 20, gender: "male", department: "Engineering" },
    { _id: 2, name: "Yasmin", age: 25, gender: "female", managerName: "Salwa", department: "HR" },
    { _id: 3, name: "Abdelghany", age: 15, gender: "male", DOB: "1970-09-03" }
])

//4. Query to find data from the "Staff" collection: 

////1) Find all documents. 
db.lab.find({})

////2) Find documents where gender is "male". 
db.lab.find({gender:"male"} , {})


////3) Find documents with age between 20 and 25. 

db.lab.find({ age: { $gte: 20, $lte: 25 } }) // first simple way 
db.lab.find({ $and: [ { age:{$gte: 20} } , { age:{$lte:25} } ]}) // more detailed 

////4) Find documents where age is 25 and gender is "female". 
db.lab.find({ $and: [ { age:25 } , { gender:"female" } ]}) // lab

////5) Find documents where age is 20 or gender is "female". 
db.lab.find({ $or: [ { age:20 } , { gender:"female" } ]}) // more detailed 


//5. Update one document in the "Staff" collection where age is 15, set the name to "new student". 

db.lab.insertOne({_id:95 , name:"Iraa" , age:15 , gender:"male" , department:"AI"})

//// if there is no student by that age that query will have no meaning
db.lab.updateOne( 
                {age:15},
                {"$set":{name:"new student"}}
) 

db.lab.find({})

//6. Update many documents in the "Staff" collection, setting the department to "AI". 
db.lab.insertOne({_id:4 , name:"Khaled" , age:105 , gender:"male" , department:"IT"})

db.lab.updateMany( 
                {}, // No Condition
                {"$set":{department:"AI"}}
) 

db.lab.find({})

//7. Create a new collection called "test" and insert documents from Question 3. 
db.test.insertMany([
    { _id: 1, name: "Ibrahim", age: 20, gender: "male", department: "Engineering" },
    { _id: 2, name: "Yasmin", age: 25, gender: "female", managerName: "Salwa", department: "HR" },
    { _id: 3, name: "Abdelghany", age: 15, gender: "male", DOB: "1970-09-03" }
])

db.test.find({})

//8. Try to delete one document from the "test" collection where age is 15. 

db.test.deleteOne({age:15})

db.test.find({})

//9. try to delete all male gender 
db.teat.insertOne({_id:4 , name:"Khaled" , age:105 , gender:"male" , department:"IT"})

db.test.deleteMany({gender: "male"})

db.test.find({})

//10. Try to delete all documents in the "test" collection. 
db.test.deleteMany({});
db.test.drop()
db.test.find({})


